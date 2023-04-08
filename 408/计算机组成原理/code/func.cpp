// 观察模板、重载、参数缺省
template <typename T>
T const& Max(T const& a, T const& b) {
    return a < b ? b : a;
}

int testCall(int a, int b) {
    return Max(a, b);
}

int add(int a, int b) {
    int c = a + b;
    return c;
}

double add(double a, double b) {
    double c = a + b;
    return c;
}

float add(float a, float b) {
    float c = a + b;
    return c;
}

int variableArgs(int a, int b = 10) {
    return a + b;
}

int testVariableArgs() {
    int a = variableArgs(5);
    int b = variableArgs(5, 11);
    return a + b;
}