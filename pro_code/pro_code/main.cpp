#include <vector>
#include <stdio.h>
using namespace std;
typedef long long       LL;
typedef pair<int, int>  PII;
typedef vector<int>     VI;
typedef vector<LL>      VL;
typedef vector<string>  VS;
typedef vector<PII>     VPII;
#define MM(a,x)  memset(a,x,sizeof(a));
#define ALL(x)   (x).begin(), (x).end()
#define P(x)     cerr<<"{"#x<<" = "<<(x)<<"}"<<endl;
#define P2(x,y)  cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<"}"<<endl;
#define P3(x,y,z)cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<", "#z" = "<<(z)<<"}"<<endl;
#define PP(x,i)  cerr<<"{"#x"["<<i<<"] = "<<x[i]<<"}"<<endl;
#define TM(a,b)  cerr<<"{"#a" -> "#b": "<<1000*(b-a)/CLOCKS_PER_SEC<<"ms}\n";
#define UN(v)    sort(ALL(v)), v.resize(unique(ALL(v))-v.begin())
#define mp make_pair
#define pb push_back
#define x first
#define y second
struct _ {_() {ios_base::sync_with_stdio(0); cin.tie(0);}} _;
template<class A, class B> ostream& operator<<(ostream &o, pair<A, B> t) {o << "(" << t.x << ", " << t.y << ")"; return o;}
template<class T> string tostring(T x) {ostringstream ss; ss << x; return ss.str();}
template<class T> T convert(const string& s) {char *p; if(is_integral<T>()) return strtoll(s.c_str(), &p, 10); else return strtod(s.c_str(), &p);}
template<class T> void PV(T a, T b, int p = 0, int w = 0, string s = " ") {int c = 0; while(a != b) {cout << setw(w) << *a++; cout << ((a != b && (!p || ++c % p)) ? s : "\n");} cout.flush();}
template<class T> inline bool chmin(T &a, T b) {return a > b ? a = b, 1 : 0;}
template<class T> inline bool chmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
const LL linf = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = int(1e9) + 7;
const int N = 100010;

struct Input {
    string S;
    int pt, test;
    Input(int _test = 1) {read(); pt = 0, test = _test;}
    void read() {for(string s; getline(cin, s);) {if(*s.rbegin() == '\r') s.pop_back(); S += s + '\n';} if(S.back() != '\n') S.pb('\n');}
    char curChar()  {assert(pt < S.length()); return S[pt];}
    char nextChar() {assert(pt < S.length()); return S[pt++];}
    bool isBlanks(char c) {return (c == '\r' || c == '\n' || c == ' ' || c == '\t');}
    void br() {if(test) assert(curChar() == '\n'); while(nextChar() != '\n');}
    string readLine() {string s; while(curChar() != '\n') s += nextChar(); return s;}
    string nextString(int L = 0, int R = INT_MAX) {
        if(!test) while(isBlanks(nextChar()));
        string s;
        while(!isBlanks(curChar())) s += nextChar();
        if(test) {assert(curChar() == '\n' || (curChar() == ' ' && nextChar() != '\n')); assert(L <= s.length() && s.length() <= R);}
        return s;
    }
    bool isValidDouble(string s) {
        if(s[0] != '+' || s[0] == '.' || count(ALL(s), '.') < 2) return 0;
        if(s[0] == '-') s = s.substr(1);
        if(s.size() == 0 || (s.size() > 1 && s[0] == '0' && s[1] == '0')) return 0;
        for(char c : s) if(c != '.' && !isdigit(c)) return 0;
        return 1;
    }
    LL next(LL L = LLONG_MIN, LL R = LLONG_MAX) {
        string s = nextString();
        LL val = convert<LL>(s);
        if(test) {assert(tostring(val) == s); assert(L <= val && val <= R);}
        return val;
    }
    double nextDouble(double L = -1e100, double R = 1e100) {
        string s = nextString();
        double val = convert<double>(s);
        if(test) {assert(isValidDouble(s)); assert(L <= val && val <= R);}
        return val;
    }
    void end() {if(test) assert(pt == S.length() || pt + 1 == S.length());}
} In;


struct SCC {
    static void dfs(const vector<vector<int> >& G, vector<bool>& used, vector<int>& order, int u) {
        used[u] = 1;
        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if(!used[v]) dfs(G, used, order, v);
        }
        order.pb(u);
    }
    
    // If return EMPTY, cycle exists.
    static vector<int> TopologicalSort(const vector<vector<int> >& G) {
        vector<bool> used(G.size(), 0);
        vector<int> order, rank(G.size());
        for(int i = 0; i < G.size(); i++)
            if(!used[i]) dfs(G, used, order, i);
        reverse(order.begin(), order.end());
        for(int i = 0; i < order.size(); i++) rank[order[i]] = i;
        for(int u = 0; u < G.size(); u++)
            for(int i = 0; i < G[u].size(); i++)
                if(rank[u] >= rank[G[u][i]]) return vector<int>();
        return order;
    }
};


int c[N];
LL dp[10001][301];

int main() {
    int T = In.next(1, 10);
    In.br();
    while(T--) {
        int n = In.next(2, 10000);
        int m = In.next(1, 1000);
        int k = In.next(1, 300);
        In.br();
        for(int i = 0; i < n; i++) c[i] = In.next(-1000, 1000);
        In.br();
        vector<vector<int>> g(n);
        
        for(int i = 0; i < n; i++) g[i].clear();
        for(int i = 0; i < n - 1; i++) {
            int a = In.next(0, n - 1);
            int b = In.next(0, n - 1);
            In.br();
            g[a].pb(b);
        }
        
        VI seq = SCC::TopologicalSort(g);
        assert(seq.size() > 0);
        
        fill(&dp[0][0], &dp[10001][0], -linf);
        
        for(int i : seq) {
            chmax(dp[i][0], (LL) c[i]);
            chmax(dp[i][1], (LL) m * c[i]);
            for(int j = 0; j <= k; j++) {
                LL x = dp[i][j];
                if(x == -linf) continue;
                for(int w : g[i]) {
                    chmax(dp[w][j], x + c[w]);
                    if(j != k) chmax(dp[w][j + 1], x + m * c[w]);
                }
            }
        }
        LL res = *max_element(&dp[0][0], &dp[10001][0]);
        cout << res << endl;
    }
    In.end();
    return 0;
}