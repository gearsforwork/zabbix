/*
** Copyright (C) 2001-2025 Zabbix SIA
**
** This program is free software: you can redistribute it and/or modify it under the terms of
** the GNU Affero General Public License as published by the Free Software Foundation, version 3.
**
** This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
** without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU Affero General Public License for more details.
**
** You should have received a copy of the GNU Affero General Public License along with this program.
** If not, see <https://www.gnu.org/licenses/>.
**/

#include "zbxmocktest.h"
#include "zbxmockdata.h"
#include "zbxmockassert.h"
#include "zbxmockutil.h"

#include "zbxlog.h"
#include "zbxexpr.h"

/******************************************************************************
 *                                                                            *
 * Purpose: get item type from its string representation                      *
 *                                                                            *
 * Parameters: item_type - [IN] the item type                                 *
 *                                                                            *
 * Return value: Corresponding ITEM_TYPE_* define value                       *
 *                                                                            *
 * Comments: This function will fail test case if unknown item_type is given. *
 *                                                                            *
 ******************************************************************************/
static unsigned char	get_item_type(const char *item_type)
{
	const char	*item_types[] = {
			"ZABBIX",
			"SNMPv1",
			"TRAPPER",
			"SIMPLE",
			"SNMPv2c",
			"INTERNAL",
			"SNMPv3",
			"ZABBIX_ACTIVE",
			"AGGREGATE",
			"HTTPTEST",
			"EXTERNAL",
			"DB_MONITOR",
			"IPMI",
			"SSH",
			"TELNET",
			"CALCULATED",
			"JMX",
			"SNMPTRAP",
			"DEPENDENT",
			NULL
	};
	int		i;

	for (i = 0; NULL != item_types[i]; i++)
	{
		if (0 == strcmp(item_types[i], item_type))
			return i;
	}

	fail_msg("Unknown item type: %s", item_type);

	return 0;
}

void	zbx_mock_test_entry(void **state)
{
	int			simple_interval, nextcheck, step = 1;
	zbx_custom_interval_t	*custom_intervals = NULL;
	char			*error = NULL, msg[4096];
	const char		*delay, *nextcheck_expected;
	zbx_mock_handle_t	checks, handle;
	unsigned char		item_type;
	zbx_mock_error_t	mock_err;
	time_t			now;
	zbx_timespec_t		ts;

	ZBX_UNUSED(state);

	if (0 != setenv("TZ", zbx_mock_get_parameter_string("in.timezone"), 1))
		fail_msg("Cannot set 'TZ' environment variable: %s", zbx_strerror(errno));

	tzset();

	delay = zbx_mock_get_parameter_string("in.delay");

	if (SUCCEED != zbx_interval_preproc(delay, &simple_interval, &custom_intervals, &error))
		fail_msg("Value of 'delay' is not a valid update interval: %s.", error);

	item_type = get_item_type(zbx_mock_get_parameter_string("in['item type']"));

	if (ZBX_MOCK_SUCCESS != zbx_strtime_to_timespec(zbx_mock_get_parameter_string("in.at"), &ts))
		fail_msg("Invalid 'at' format");

	now = ts.sec;
	checks = zbx_mock_get_parameter_handle("out.checks");

	while (ZBX_MOCK_END_OF_VECTOR != (mock_err = (zbx_mock_vector_element(checks, &handle))))
	{
		if (ZBX_MOCK_SUCCESS != mock_err)
			fail_msg("Cannot read 'checks' element #%d: %s", step, zbx_mock_error_string(mock_err));

		if (ZBX_MOCK_SUCCESS != (mock_err = zbx_mock_string(handle, &nextcheck_expected)))
			fail_msg("Cannot read 'checks' element #%d value: %s", step, zbx_mock_error_string(mock_err));

		if (ZBX_MOCK_SUCCESS != (mock_err = zbx_strtime_to_timespec(nextcheck_expected, &ts)))
		{
			fail_msg("Cannot convert 'checks' element #%d value to time: %s", step,
					zbx_mock_error_string(mock_err));
		}

		nextcheck = zbx_calculate_item_nextcheck(0, item_type, simple_interval, custom_intervals, now);

		zbx_snprintf(msg, sizeof(msg), "Invalid nextcheck calculation step %d", step++);
		zbx_mock_assert_time_eq(msg, ts.sec, nextcheck);

		now = nextcheck;
	}

	zbx_custom_interval_free(custom_intervals);
}
