void imprimirElemento(char e){
    printf("%c", e);
}
int esParentesisIzq(char e){
    return e == '(';
}
int esParentesisDer(char e){
    return e == ')';
}
int esOperadorS(char e){
    return e=='^' || e=='*' || e=='/' || e=='+' || e== '-';
}
int prioridad(char e){
    switch (e){
        case '^':
            return e=3;
            break;
        case '*':
            return e=2;
            break;
        case '/':
            return e=2;
            break;
        case '+':
            return e=1;
            break;
        case '-':
            return e=1;
            break;
        default:
            break;
        }
}