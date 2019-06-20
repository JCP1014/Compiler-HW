.class public compiler_hw3
.super java/lang/Object
.field public static c F = 1.500000
.method public static loop(II)Z
.limit stack 50
.limit locals 50
BEGIN1_1:
	iload 0
	iload 1
	isub
	ifgt TRUE1_1
	goto FALSE1_1
TRUE1_1:
	iload 0
	ldc 1
	isub
	istore 0
	goto BEGIN1_1
FALSE1_1:
	ldc 1
	ireturn
.end method
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 0
	istore 0
	ldc 0
	istore 1
	ldc 5
	istore 2
	iload 2
	ldc 10
	isub
