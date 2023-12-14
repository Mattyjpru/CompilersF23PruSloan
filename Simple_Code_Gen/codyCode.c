//Symbol Table stuff
    int st_count=0;
    char useBuff[16];

    #define MAX_ST_SIZE 48
    #define MAX_ST_STACK_SIZE 30

    struct SymTabEntry{
        char* name;
        char* d_type;
        char* use;
        int intval;
        float dubval;
        int line_no;
        char* memLoc;
    }InitialSymTab[MAX_ST_SIZE];

    struct SymTabStack{
        struct SymTabEntry SymbolTable[MAX_ST_STACK_SIZE][MAX_ST_SIZE];
        int top;
    }ST_Stack;

    ST_Stack->top = -1; // empty stack

    struct SymTabRtnValue{
        char* strVal;
        int intVal;
        double floatVal;
    };

    // Code Gen stuff
    struct node{
        char* token;
        struct node* leftchild;
        struct node* rightchild;
        // char* dataType;
    };