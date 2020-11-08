int main() {
    int u;
    int x;
    int y;
    int z;
    u = 9 * 2;
    y = 12;
    scanf("%d", &x);
    z = x + u;
    if (x > 15) {
        u = 3*6;
        z = x + u;
    } else {
        u = (4*7) + 3;
        z = x + u;
    }

    u = (x - y) * u;

    printf("%d\n", z);
    printf("%d\n", u);
    return 0;
}
