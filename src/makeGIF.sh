#/bin/sh

convert                                                  
  -delay 10                                              
   $(for i in $(seq 0 5 100); do echo foo${i}.png; done) 
  -loop 0                                                
  animated.gif


