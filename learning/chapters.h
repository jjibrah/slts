#ifndef SECTION_H_INCLUDED
#define SECTION_H_INCLUDED

const char *tutorials[] = {
     "1. A Tutorial Introduction",
     "2. Types, Operators and Expressions",
     "3. Control Flow",
     "4. Functions and Program Structure",
     "5. Pointers and Arrays",
     "6. Structures",
     "7. Input and Output"
};

const char *section1[] = {
    "01  A Tutorial Introduction; (1)","02  Getting Started; (1)","03  Variables and Arithmetic Expressions; (3)",
    "04  The for statement; (1)","05  Symbolic Constants; (2)","06  Character Input and Output; (2)","07  Arrays; (1)",
    "08  Functions; (1)","09  Arguments; (1)","10  Call by Value; (1)","11  Character Arrays; (1)","12  External Variables and Scope; (2)"
};

const char *section2[] = {
    "01  Variable Names; (2)","02  Data Types and Sizes; (2)","03  Constants; (1)","04  Declarations; (1)",
    "05  Arithmetic Operators; (2)","06  Relational and Logical Operators; (2)","07  Type Conversions; (2)",
    "08  Increment and Decrement Operators; (2)","09  Bitwise Operators; (2)","10  Assignment Operators and Expressions; (2)",
    "11  Conditional Expressions; (2)","12  Precedence and Order of Evaluation; (2)"
};

const char *section3[] = {
    "01  Statements and Blocks; (1)","02  If-Else; (1)","03  Else-If; (1)","04  Switch;  (1)","05  While;   (1)","06  For;     (1)",
    "07  Do-While; (1)","08  Break and Continue; (2)","09  Goto and labels; (1)"
};

const char *section4[] = {
    "01  Basics of Functions; (1)","02  Functions Returning Non-integers; (1)","03  External Variables; (1)","04  Scope Rules; (1)",
    "05  Header Files; (1)","06  Static Variables; (1)","07  Register Variables; (1)","08  Block Structure; (1)",
    "09  Initialization; (2)","10  Recursion; (2)","11  The C Preprocessor; (1)"
};

const char *section5[] = {
    "01  Pointers and Addresses; (1)","02  Pointers and Function Arguments; (2)","03  Pointers and Arrays; (1)","04  Address Arithmetic; (1)",
    "05  Character Pointers and Functions; (2)","06  Pointer Arrays; (1)","07  Pointers to Pointers; (1)","08  Multi-dimensional Arrays; (1)",
    "09  Initialization of Pointer Arrays; (1)","10  Pointers vs Multi-dimensional Arrays; (1)","11  Command-line Arguments; (1)",
    "12  Pointers to Functions; (1)","13  Complicated Declarations; (2)"
};

const char *section6[] = {
    "01  Basics of Structures; (1)","02  Structures and Functions; (2)","03  Arrays of Structures; (1)",
    "04  Pointers to Structures; (1)","05  Self-referential Structures; (1)","06  Table Lookup; (1)",
    "07  Typedef; (1)","08  Unions; (1)","09  Bit-fields; (2)"
};

const char *section7[] = {
    "01  Standard Input and Output; (2)","02  Formatted Output printf; (1)","03  Variable-length Argument Lists; (1)",
    "04  Formatted Input Scanf; (1)","05  File Access; (1)","06  Error Handling Stderr and Exit; (2)","07  Line Input and Output; (2)",
    "08  Miscellaneous Functions; (2)"
};

struct cumulativeLearningTime{
    char stdno[20];
    int courseNumber;
    int chapterNumber;
    int unitNumber;
    long elapsedLearningTime;

};


#endif // SECTION_H_INCLUDED
