int foo(int a, float b) {
   a += 6;
   return a;
}

void lol(int a) {
    print(a);
	return;
}

void main(){
   int a;
   a = foo(4,5.0);
   lol(a);
   return;
}

