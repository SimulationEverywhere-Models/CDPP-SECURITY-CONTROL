[top]
components : pinreader@PinReader queue@Queue cpu1@CPU1 cpu2@CPU2 doorlatch@DoorLatch
in : in
out : out
Link : in in@pinreader
Link : out@pinreader in@queue
Link : out@queue in@cpu1
Link : out@cpu1 done@queue
Link : out@cpu1 in@cpu2
Link : out@cpu2 in@doorlatch
Link : out@doorlatch out

[pinreader]
distribution : normal
mean : 2
deviation : 1

[queue]
preparation : 0:0:10:0

[cpu1]
distribution : exponential
mean : 10

[cpu2]
distribution : exponential
mean : 10

[doorlatch]
distribution : normal
mean : 2
deviation : 1