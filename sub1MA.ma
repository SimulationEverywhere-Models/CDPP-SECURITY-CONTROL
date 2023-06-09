[top]
components : pinreader@PinReader queue@Queue cpu@CPU1
in : in
out : out
Link : in in@pinreader
Link : out@pinreader in@queue
Link : out@queue in@cpu
Link : out@cpu out
Link : out@cpu done@queue

[pinreader]
distribution : normal
mean : 2
deviation : 1

[queue]
preparation : 0:0:10:0

[cpu]
distribution : exponential
mean : 10