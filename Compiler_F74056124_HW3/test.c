int a = 9;
bool foo(){

	bool b = true;
	return b;
}
void main(){
   if(a>3){
	a -=3;
	if(a<=0){
		print("error");
	}else if(a==6){
		int b = 0;
		print(b);
		while(b < 8){
			print(b);
			b++;
		}
	}
}
	
	if(a>=2){
		bool c = foo();
		print(c);
	}
	return;
}

