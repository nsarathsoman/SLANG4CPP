numeric a;

//input
a=5;

numeric result;

result=1;

while(a>0)

result = result * a;
a = a-1;

wend

printline "factorial is ";

print result;