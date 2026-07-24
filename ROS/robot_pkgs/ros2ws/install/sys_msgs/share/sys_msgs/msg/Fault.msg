# 故障产生时间，毫秒时间戳
uint64 time_stamp_ms
# 故障码
uint64 code

# 故障状态，故障产生|故障消除
uint16 STATUS_CLEAR = 0
uint16 STATUS_ACTIVE = 1
uint16 status