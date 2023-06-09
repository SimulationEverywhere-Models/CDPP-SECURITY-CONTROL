[top]
components : cpu@CPU2 doorlatch@DoorLatch
in : in
out : out
Link : in in@cpu
Link : out@cpu in@doorlatch
Link : out@doorlatch out

[cpu]
distribution : exponential
mean : 10

[doorlatch]
distribution : normal
mean : 2
deviation : 1


