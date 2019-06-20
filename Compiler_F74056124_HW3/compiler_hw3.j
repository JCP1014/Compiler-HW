.class public compiler_hw3
.super java/lang/Object
.field public static a I = 6
.field public static b I = 0
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 4
	getstatic compiler_hw3/a I
	iadd
	i2f
	fstore 0
	fload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	return
.end method
