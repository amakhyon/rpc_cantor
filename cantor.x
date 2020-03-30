

struct pair {
    int x; int y;
};
typedef pair pairs<>;
typedef int results<>;




program Cantor {

    version Cantor_Vers {
        results CantorForeward(pairs) =1;
        pairs CantorBackward(results) = 2;
    } =1;

}= 0x1234;
