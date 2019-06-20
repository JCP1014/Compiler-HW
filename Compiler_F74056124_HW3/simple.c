float foo(int a) {
   a += 6;
   return 3.0;
}

void lol(int a) {
    print(a);
	return;
}

void main(){
   int a;
   a = foo(4);
   lol(a);
   return;
}

