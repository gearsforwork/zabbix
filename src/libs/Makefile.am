## Process this file with automake to produce Makefile.in

DIST_SUBDIRS = \
	zbxalgo \
	zbxalerter \
	zbxasyncpoller \
	zbxasynchttppoller \
	zbxaudit \
	zbxautoreg \
	zbxavailability \
	zbxbincommon \
	zbxconnector \
	zbxcommon \
	zbxcomms \
	zbxcommshigh \
	zbxcompress \
	zbxcfg \
	zbxcrypto \
	zbxcurl \
	zbxdb \
	zbxcacheconfig \
	zbxcachehistory \
	zbxcachevalue \
	zbxdbhigh \
	zbxdiscoverer \
	zbxdbwrap \
	zbxdbsyncer \
	zbxdbschema \
	zbxdbupgrade \
	zbxdiag \
	zbxdiscovery \
	zbxembed \
	zbxescalations \
	zbxeval \
	zbxevent \
	zbxexec \
	zbxexport \
	zbxexpr \
	zbxfile \
	zbxgetopt \
	zbxhash \
	zbxhistory \
	zbxhttp \
	zbxhttppoller \
	zbxicmpping \
	zbxinterface \
	zbxip \
	zbxipcservice \
	zbxipmi \
	zbxjson \
	zbxkvs \
	zbxlog \
	zbxmedia \
	zbxmodules \
	zbxmutexs \
	zbxnix \
	zbxnum \
	zbxodbc \
	zbxparam \
	zbxpgservice \
	zbxpinger \
	zbxpoller \
	zbxagentget \
	zbxpreproc \
	zbxpreprocbase \
	zbxprometheus \
	zbxproxybuffer \
	zbxregexp \
	zbxrtc \
	zbxscripts \
	zbxself \
	zbxserialize \
	zbxexpression \
	zbxservice \
	zbxshmem \
	zbxsnmptrapper \
	zbxsysinfo \
	zbxstats \
	zbxstr \
	zbxtagfilter \
	zbxtasks \
	zbxthreads \
	zbxtime \
	zbxtimekeeper \
	zbxtrapper \
	zbxtrends \
	zbxvariant \
	zbxvault \
	zbxversion \
	zbxvmware \
	zbxprof \
	zbxxml

if SERVER
SERVER_SUBDIRS = \
	zbxalerter \
	zbxasynchttppoller \
	zbxasyncpoller \
	zbxaudit \
	zbxautoreg \
	zbxavailability \
	zbxbincommon \
	zbxconnector \
	zbxcompress \
	zbxdb \
	zbxdiscovery \
	zbxdiscoverer \
	zbxcacheconfig \
	zbxcachehistory \
	zbxcachevalue \
	zbxdbhigh \
	zbxdbwrap \
	zbxdbsyncer \
	zbxdbschema \
	zbxdbupgrade \
	zbxdiag \
	zbxembed \
	zbxescalations \
	zbxeval \
	zbxevent \
	zbxexport \
	zbxexpr \
	zbxhistory \
	zbxhttp \
	zbxhttppoller \
	zbxicmpping \
	zbxinterface \
	zbxip \
	zbxipcservice \
	zbxkvs \
	zbxmedia \
	zbxnum \
	zbxodbc \
	zbxparam \
	zbxpgservice \
	zbxpinger \
	zbxpoller \
	zbxpreproc \
	zbxpreprocbase \
	zbxprometheus \
	zbxproxybuffer \
	zbxrtc \
	zbxscripts \
	zbxself \
	zbxserialize \
	zbxexpression \
	zbxservice \
	zbxshmem \
	zbxsnmptrapper \
	zbxstats \
	zbxstr \
	zbxtagfilter \
	zbxtasks \
	zbxtime \
	zbxtimekeeper \
	zbxtrends \
	zbxtrapper \
	zbxvariant \
	zbxvault \
	zbxversion \
	zbxvmware \
	zbxxml
if HAVE_IPMI
SERVER_SUBDIRS += zbxipmi
endif
else
if PROXY
PROXY_SUBDIRS = \
	zbxasyncpoller \
	zbxasynchttppoller \
	zbxaudit \
	zbxautoreg \
	zbxavailability \
	zbxbincommon \
	zbxconnector \
	zbxcompress \
	zbxdb \
	zbxdiscovery \
	zbxdiscoverer \
	zbxcacheconfig \
	zbxcachehistory \
	zbxcachevalue \
	zbxdbhigh \
	zbxdbwrap \
	zbxdbsyncer \
	zbxdbschema \
	zbxdbupgrade \
	zbxdiag \
	zbxembed \
	zbxescalations \
	zbxeval \
	zbxevent \
	zbxexport \
	zbxhistory \
	zbxhttp \
	zbxhttppoller \
	zbxicmpping \
	zbxinterface \
	zbxip \
	zbxipcservice \
	zbxkvs \
	zbxnum \
	zbxodbc \
	zbxparam \
	zbxpgservice \
	zbxpinger \
	zbxpoller \
	zbxpreproc \
	zbxpreprocbase \
	zbxprometheus \
	zbxproxybuffer \
	zbxrtc \
	zbxself \
	zbxserialize \
	zbxexpression \
	zbxscripts \
	zbxshmem \
	zbxsnmptrapper \
	zbxstats \
	zbxstr \
	zbxtagfilter \
	zbxtasks \
	zbxtime \
	zbxtimekeeper \
	zbxtrends \
	zbxtrapper \
	zbxvariant \
	zbxvault \
	zbxversion \
	zbxvmware \
	zbxxml
if HAVE_IPMI
PROXY_SUBDIRS += zbxipmi
endif
endif
endif

SUBDIRS = \
	zbxalgo \
	zbxbincommon \
	zbxcommon \
	zbxcomms \
	zbxcommshigh \
	zbxcompress \
	zbxcfg \
	zbxcrypto \
	zbxcurl \
	zbxexec \
	zbxexpr \
	zbxfile \
	zbxgetopt \
	zbxhash \
	zbxhttp \
	zbxinterface \
	zbxip \
	zbxjson \
	zbxlog \
	zbxmodules \
	zbxmutexs \
	zbxprof \
	zbxnix \
	zbxnum \
	zbxparam \
	zbxregexp \
	zbxsysinfo \
	zbxstr \
	zbxthreads \
	zbxtime \
	zbxvariant \
	zbxversion \
	zbxxml \
	zbxagentget \
	$(PROXY_SUBDIRS) \
	$(SERVER_SUBDIRS) \
	$(AGENT_SUBDIRS)

EXTRA_DIST = \
	zbxwin32 \
	zbxwinservice

## hashicorp and cyberark used to be a separate libraries, remove them at some point in the future
clean: clean-recursive
	rm -rf hashicorp && \
	rm -rf cyberark
.PHONY: clean
