# vmTetris

Tetris in a small virtual machine.
Use the cursor keys.
Press `esc` to quit.

```c
m[444],c,x;main(o,a){for(system("stty cbreak -echo min 0"),srand(a);o=f();o<42?a
=(x=o/2%7)<3?x:x<4?f():x<5?m[f()<23?x:m[x-23]]:x<6?getchar():rand()%f(),m[x=o%2?
f():m[6]++]*=o<28,a=m[x]+=o>13?a:-a:o<45?putchar(o%3?o%2*75+f():a):o<63?f(),c=!a
^o/54?x+o%9*75:c:usleep(20000));system("stty sane");}f(){return x=c++["NCRM7@BD\
;527e4R37Q<Q9M27e@Q:OQ9MQ9Q;MQ9OMQ;Q9B7MQEQ:Q:OM27e^MQEMQ:OQ8KMQEOQ8OMQDMKQ:OMM\
QDQ:OQ:P7KMQ;OQ:Q927fDP7MMQ8MQ;Q:27fSRE5RE<Q6D952<ffR;<Q62<fr[JZ?[a[y`NT=>T?@LD\
2C^bT<7V<@<gC6K7bn6U7g^68?^^D;?27gjD:=NDTBC27gp@=27gv2=P8RE5RF<R;;TL747hB47K25T\
=9D;9859_lTA:F?:T=9R26FQ9859_lF59@:26hY`?B7`;RI98=9bn>D`3N8T@?T>=gxS825=2;h6252\
<h328k:RI=X66DM6R:9T6AF6A29i]X2?T?9F9?F9?RE5RE<TL7=27bn2<ivR[5RD<=R9;R97N98L9jM\
27=2;jD>7k6T5;L558a[25C9T;5>/jl2BT5;T576:7SN456F7joT;52<j=[JZ?[j[wR[5RD<R;;[JZ?\
[cTL7D_7YZQ[O[O=2;kK25[92<kHn^7[JZ?ZQR35TL9l525kw=25C_Y25l6[9/"]-47;}/*********/
```
