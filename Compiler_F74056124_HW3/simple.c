int foo(int a);
int foo() {

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

