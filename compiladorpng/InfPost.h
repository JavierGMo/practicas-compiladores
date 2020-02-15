/*Agreagar el peso de los operadoress*/
int parentesiSIzquierdo(char e){
    return e == '(';
}
int parentesisDerecho(char e){
    return e == ')';
}
int operador(char e){
    return e=='^' || e=='*'||  e=='/' || e=='+' || e=='-';
}
char agregarPunto(){
    return '.';
}