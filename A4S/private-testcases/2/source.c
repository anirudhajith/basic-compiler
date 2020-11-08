int main() {
    int a;
    int b;
    int c;
    int d;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);

    a = b + c;
    d = (b + c);
    d = (b + c) + (b + c);

    scanf("%d", &b);
    d = ((b + c) + (b + c)) + (b + c);



    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    printf("%d\n", d);
    return 0;
}
