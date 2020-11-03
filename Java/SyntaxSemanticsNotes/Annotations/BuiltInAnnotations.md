Annotations
Notice the @Override line above the method declaration? This is known as an annotation. In Java, annotations are metadata that we add to our code to provide extra information to the compiler. When we use the @Override annotation, we are informing the compiler that the method that follows is meant to override the method declared in the base class.

Java provides a feature that enables you to embed supplemental information into a source file. This information, called an annotation, does not change the actions of a program. However, this information can be used by various tools, during both development and deployment. For example, an annotation might be processed by a source-code generator, by the compiler, or by a deployment tool. The term metadata is also used to refer to this feature, but the term annotation is the most descriptive, and more commonly used.

Using the @Override annotation is optional when overriding a method. However, you are strongly encouraged to do so to prevent compilation errors. Annotations follow a fixed syntax and are case sensitive.

Java comes with a number of predefined annotations. You can find the full list of predefined annotations here https://docs.oracle.com/javase/tutorial/java/annotations/predefined.html

An annotation is created through a mechanism based on the interface. Here is a simple example:
@interface MyAnno {
    String str();
    int val();
}

This declares an annotation called MyAnno. Notice the @ that precedes the keyword interface. This tells the compiler that an annotation type is being declared. Next, notice the two members str( ) and val( ). All annotations consist solely of method declarations. However, you don’t provide bodies for these methods. Instead, Java implements these methods. Moreover, the methods act much like fields. All annotation types automatically extend the Annotation interface. Thus, Annotation is a super-interface of all annotations. It is declared within the java.lang.annotation package. Originally, annotations were used to annotate only declarations. In this usage, any type of declaration can have an annotation associated with it. For example, classes, methods, fields, parameters, and enum constants can be annotated. Even an annotation can be annotated. In such cases, the annotation precedes the rest of the declaration. Beginning with JDK 8, you can also annotate a type use, such as a cast or a method return type. When you apply an annotation, you give values to its members. For example, here is an example of MyAnno being applied to a method:

@MyAnno (str = "Annotation Example", val =100)
public static void myMethod() { //actions... }

This annotation is linked with the method myMeth( ). Look closely at the annotation syntax. The name of the annotation, preceded by an @, is followed by a parenthesized list of member initializations. To give a member a value, that member’s name is assigned a value. Therefore, in the example, the string "Annotation Example" is assigned to the str member of MyAnno. Notice that no parentheses follow str in this assignment. When an annotation member is given a value, only its name is used. Thus, annotation members look like fields in this context. Annotations that don’t have parameters are called marker annotations. These are specified without passing any arguments and without using parentheses. Their sole purpose is to mark an item with some attribute. Java defines many built-in annotations. Most are specialized, but nine are general purpose. Four are imported from java.lang.annotation: @Retention, @Documented, @Target, and @Inherited. Five, @Override, @Deprecated, @SafeVarargs, @FunctionalInterface, and @SuppressWarnings, are included in java.lang.

[Annotations.png]

https://en.wikipedia.org/wiki/Java_annotation
