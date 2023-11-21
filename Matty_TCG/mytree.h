program: headers main '(' ')' '{' body return '}' { $2.nd = mknode($6.nd, $7.nd, "main"); $$.nd = mknode($1.nd, $2.nd, "program"); head = $$.nd; } 
;

headers: headers headers { $$.nd = mknode($1.nd, $2.nd, "headers"); }

| INCLUDE { add('H'); } { $$.nd = mknode(NULL, NULL, $1.name); }
;

main: datatype ID { add('K'); }
;

datatype: INT { insert_type(); }

| FLOAT { insert_type(); }

| CHAR { insert_type(); }

| VOID { insert_type(); }
;

body: FOR { add('K'); } '(' statement ';' condition ';' statement ')' '{' body '}' 
{ struct node *temp = mknode($6.nd, $8.nd, "CONDITION"); 
struct node *temp2 = mknode($4.nd, temp, "CONDITION"); $$.nd = mknode(temp2, $11.nd, $1.name); }

| IF { add('K'); } '(' condition ')' '{' body '}' 
else { struct node *iff = mknode($4.nd, $7.nd, $1.name); 	$$.nd = mknode(iff, $9.nd, "if-else"); }

| statement ';' { $$.nd = $1.nd; }

| body body { $$.nd = mknode($1.nd, $2.nd, "statements"); }

| PRINTFF { add('K'); } '(' STR ')' ';' { $$.nd = mknode(NULL, NULL, "printf"); }

| SCANFF { add('K'); } '(' STR ',' '&' ID ')' ';' { $$.nd = mknode(NULL, NULL, "scanf"); }
;

else: ELSE { add('K'); } '{' body '}' { $$.nd = mknode(NULL, $4.nd, $1.name); }

| { $$.nd = NULL; }
;

condition: value relop value { $$.nd = mknode($1.nd, $3.nd, $2.name); }

| TRUE { add('K'); $$.nd = NULL; }

| FALSE { add('K'); $$.nd = NULL; }

| { $$.nd = NULL; }
;

statement: datatype ID { add('V'); } init { $2.nd = mknode(NULL, NULL, $2.name); $$.nd = mknode($2.nd, $4.nd, "declaration"); }

| ID '=' expression { $1.nd = mknode(NULL, NULL, $1.name); $$.nd = mknode($1.nd, $3.nd, "="); }

;

init: '=' value { $$.nd = $2.nd; }

| { $$.nd = mknode(NULL, NULL, "NULL"); }
;

expression: expression arithmetic expression { $$.nd = mknode($1.nd, $3.nd, $2.name); }

| value { $$.nd = $1.nd; }
;

arithmetic: ADD 

| SUBTRACT 

| MULTIPLY

| DIVIDE
;

relop: LT

| GT

| LE

| GE

| EQ

| NE
;

value: NUMBER { add('C'); $$.nd = mknode(NULL, NULL, $1.name); }

| FLOAT_NUM { add('C'); $$.nd = mknode(NULL, NULL, $1.name); }

| CHARACTER { add('C'); $$.nd = mknode(NULL, NULL, $1.name); }

| ID { $$.nd = mknode(NULL, NULL, $1.name); }
;

return: RETURN { add('K'); } value ';' { $1.nd = mknode(NULL, NULL, "return"); $$.nd = mknode($1.nd, $3.nd, "RETURN"); }

| { $$.nd = NULL; }
;

%%
