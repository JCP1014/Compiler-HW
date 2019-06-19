.class public compiler_hw3
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 1
	istore 0
BEGIN1_1:
	iload 0
	ldc 6
	isub
	iflt TRUE1_1
	goto FALSE1_1
TRUE1_1:
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	iload 0
	ldc 1
	iadd
	istore 0
	goto BEGIN1_1
FALSE1_1:
	return
.end method
