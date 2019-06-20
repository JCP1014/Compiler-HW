int foo(int a) {
   a += 6;
   return a;
}

void lol(float a) {
    print(a);
	return;
}

void main(){
   float a;
   a = foo(4);
   lol(a);
   return;
}

