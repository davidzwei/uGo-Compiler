# uGo-Compiler
A simple compiler that can compile uGo to JVM instructions.

![](https://github.com/davidzwei/uGo-Compiler/blob/main/img/compiler-flow.png)

Implement a simple compiler that can compile micro Go to Java assembly code by Yacc, Lex. The generated code will then be translated to the Java bytecode by the Java assembler, Jasmin. The generated Java bytecode should be run by the Java Virtual Machine (JVM).

### Environment
- Recommended OS: Ubuntu 18.04
- Install dependencies: ```$ sudo apt install flex bison```
- Java Virtual Machine (JVM): ```$ sudo apt install default-jre```
- Java Assembler (Jasmin) is included in the Compiler hw3 file.

### Compile
generate an executable named mycompiler.
```bash
$ make 
```

### Run

```test.c``` can be any other file.
generate the corresponding Java assembly code ( ```.j``` file)
```bash
$ ./myparser < input.go 
```

### Turn to JVM class

generate ```Main.class``` .
```bash
$ java -jar jasmin.jar compiler_hw3.j
```

### Run on JVM
Run the Java program ( ```.class``` file) with Java Virtual Machine (JVM).
```bash
$ java Main.class
```

### Other Details
You can see from the document.

