int main() {
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	int g;
	int h;
	int i;
	int j; 
	int o;
	c = -1;
	a = 2999;
	b = 2999 % 6;
	d = 0;
	i = 90;
	j = 85;
	/*
	a = 2999
	b = 5
	c = -1
	d = 0
	e = 0
	f = 0
	g = 0
	h = 0
	i = 90
	j = 85
	o = 0
	*/
	
	while (b >= 1) {
		c = c + 1;
		b = b - 1;
		d = !d;
		i = i - 1;
		j = j + 1;
	}
	/*
	a = 2999
	b = 0
	c = 4
	d = -1
	e = 0
	f = 0
	g = 0
	h = 0
	i = 85
	j = 90
	o = 0
	*/
	
	b = c % 2;
	a = c;
	e = b && d;
	f = 21 * a;
	g = 786 - f;
	h = 13 * 51;
	h = h / 3;
	j = h > g;

	/*
	a = 4
	b = 0
	c = 4
	d = -1
	e = 0
	f = 84
	g = 702
	h = 221
	i = 85
	j = 0
	o = 0
	*/
	
	if (!b) {
		int k;
		int l;
		l = 11 + 2;
		k = g;
		k = k % l;
		a = k;
		printf("%d\n", a);
	}
	else {
		int m;
		int n;
		m = i;
		n = j;
		b = m == n;
		printf("%d\n", b);
	}

	/*
	a = 4
	b = 0
	c = 4
	d = -1
	e = 0
	f = 84
	g = 702
	h = 221
	i = 85
	j = 0
	k = 0
	l = 0
	m = 85
	n = 0
	o = 0
	*/
/*
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	printf("%d\n", d);
	printf("%d\n", e);
	printf("%d\n", f);
	printf("%d\n", g);
	printf("%d\n", h);
	printf("%d\n", i);
	printf("%d\n", j);
	printf("%d\n", k);
	printf("%d\n", l);
	printf("%d\n", m);
	printf("%d\n", n);
	printf("%d\n", o);
*/
	o = !j;
	
	if (o || (-51)) {
		printf("%d\n", c);
		printf("%d\n", e);
		printf("%d\n", g);
		printf("%d\n", i);
	}
	else {
		printf("%d\n", d);
		printf("%d\n", f);
		printf("%d\n", h);
		printf("%d\n", j);
	}
	
}
