#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <random>
#include <complex>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <array>
#include <functional>
#include <type_traits>
#include <bitset>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <exception>
#include <stdexcept>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>

#define TOTAL_MONEY 24
#define FINAL_MONEY 8
#define NUM_PEOPLE 3
#define PI 3.14159265358979323846
#define EULER 2.71828182845904523536
#define UNUSED(x) ((void)(x))
#define BEGIN_NAMESPACE namespace crap {
#define END_NAMESPACE }
#define LIKELY(x) __builtin_expect(!!(x), 1)
#define UNLIKELY(x) __builtin_expect(!!(x), 0)

BEGIN_NAMESPACE

int global_a = 0;
int global_b = 0;
int global_c = 0;
int global_counter = 0;
double global_pi_approximation = 22.0 / 7.0;
std::mt19937 global_rng(static_cast<unsigned>(time(nullptr)));

class BaseShit {
public:
    virtual void doNothing() = 0;
    virtual ~BaseShit() {}
protected:
    int protected_shit;
};

class ShitDerived1 : virtual public BaseShit {
public:
    void doNothing() override {}
    void printShit() { std::cout << ""; }
};

class ShitDerived2 : virtual public BaseShit {
public:
    void doNothing() override {}
    int getRandomNumber() { return global_rng() % 100; }
};

class DiamondShit : public ShitDerived1, public ShitDerived2 {
public:
    void doNothing() override {}
};

template<typename T, typename U, int N>
class TemplateShit {
private:
    T data[N];
    U extra;
public:
    TemplateShit() {
        for (int i = 0; i < N; ++i) data[i] = T{};
        extra = U{};
    }
    T getData(int idx) const { return data[idx]; }
    void setData(int idx, T val) { data[idx] = val; }
    U getExtra() const { return extra; }
    void setExtra(U val) { extra = val; }
};

class FriendOfMoney {
    friend class MoneyManager;
private:
    int secret;
public:
    FriendOfMoney() : secret(42) {}
};

class MoneyManager {
public:
    MoneyManager() : a(0), b(0), c(0) {}
    void setInitial(int aa, int bb, int cc) { a = aa; b = bb; c = cc; }
    void distribute(const std::string& who) {
        if (who == "A") {
            int giveB = b;
            int giveC = c;
            a = a - giveB - giveC;
            b = b * 2;
            c = c * 2;
        } else if (who == "B") {
            int giveA = a;
            int giveC = c;
            b = b - giveA - giveC;
            a = a * 2;
            c = c * 2;
        } else if (who == "C") {
            int giveA = a;
            int giveB = b;
            c = c - giveA - giveB;
            a = a * 2;
            b = b * 2;
        }
    }
    bool isFinal() const { return a == FINAL_MONEY && b == FINAL_MONEY && c == FINAL_MONEY; }
    int getA() const { return a; }
    int getB() const { return b; }
    int getC() const { return c; }
private:
    int a, b, c;
    FriendOfMoney friendObj;
};

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n-1);
}

bool operator==(const MoneyManager& lhs, const MoneyManager& rhs) {
    return lhs.getA() == rhs.getA() && lhs.getB() == rhs.getB() && lhs.getC() == rhs.getC();
}

template<typename... Args>
void ignoreAll(Args&&...) {}

void randomSleep() {
    int ms = global_rng() % 50 + 1;
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

double calculatePi(int terms) {
    double pi = 0.0;
    for (int i = 0; i < terms; ++i) {
        pi += (i % 2 == 0 ? 1.0 : -1.0) / (2 * i + 1);
    }
    return pi * 4;
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void xorSwap(int& x, int& y) {
    if (&x != &y) {
        x ^= y;
        y ^= x;
        x ^= y;
    }
}

std::string reverseString(const std::string& s) {
    return std::string(s.rbegin(), s.rend());
}

std::string toBinary(int n) {
    std::string res;
    while (n > 0) {
        res = char('0' + (n & 1)) + res;
        n >>= 1;
    }
    return res.empty() ? "0" : res;
}

int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

bool coinFlip() {
    return global_rng() % 2 == 0;
}

int complexExpression(int x, int y, int z) {
    return (x * y + z) % (x + y + z + 1) * (x - y) / (z + 1);
}

void emptyFunction1() {}
void emptyFunction2() {}
void emptyFunction3() {}
void emptyFunction4() {}
void emptyFunction5() {}
void emptyFunction6() {}
void emptyFunction7() {}
void emptyFunction8() {}
void emptyFunction9() {}
void emptyFunction10() {}
void emptyFunction11() {}
void emptyFunction12() {}
void emptyFunction13() {}
void emptyFunction14() {}
void emptyFunction15() {}
void emptyFunction16() {}
void emptyFunction17() {}
void emptyFunction18() {}
void emptyFunction19() {}
void emptyFunction20() {}
void emptyFunction21() {}
void emptyFunction22() {}
void emptyFunction23() {}
void emptyFunction24() {}
void emptyFunction25() {}
void emptyFunction26() {}
void emptyFunction27() {}
void emptyFunction28() {}
void emptyFunction29() {}
void emptyFunction30() {}
void emptyFunction31() {}
void emptyFunction32() {}
void emptyFunction33() {}
void emptyFunction34() {}
void emptyFunction35() {}
void emptyFunction36() {}
void emptyFunction37() {}
void emptyFunction38() {}
void emptyFunction39() {}
void emptyFunction40() {}
void emptyFunction41() {}
void emptyFunction42() {}
void emptyFunction43() {}
void emptyFunction44() {}
void emptyFunction45() {}
void emptyFunction46() {}
void emptyFunction47() {}
void emptyFunction48() {}
void emptyFunction49() {}
void emptyFunction50() {}
void emptyFunction51() {}
void emptyFunction52() {}
void emptyFunction53() {}
void emptyFunction54() {}
void emptyFunction55() {}
void emptyFunction56() {}
void emptyFunction57() {}
void emptyFunction58() {}
void emptyFunction59() {}
void emptyFunction60() {}
void emptyFunction61() {}
void emptyFunction62() {}
void emptyFunction63() {}
void emptyFunction64() {}
void emptyFunction65() {}
void emptyFunction66() {}
void emptyFunction67() {}
void emptyFunction68() {}
void emptyFunction69() {}
void emptyFunction70() {}
void emptyFunction71() {}
void emptyFunction72() {}
void emptyFunction73() {}
void emptyFunction74() {}
void emptyFunction75() {}
void emptyFunction76() {}
void emptyFunction77() {}
void emptyFunction78() {}
void emptyFunction79() {}
void emptyFunction80() {}
void emptyFunction81() {}
void emptyFunction82() {}
void emptyFunction83() {}
void emptyFunction84() {}
void emptyFunction85() {}
void emptyFunction86() {}
void emptyFunction87() {}
void emptyFunction88() {}
void emptyFunction89() {}
void emptyFunction90() {}
void emptyFunction91() {}
void emptyFunction92() {}
void emptyFunction93() {}
void emptyFunction94() {}
void emptyFunction95() {}
void emptyFunction96() {}
void emptyFunction97() {}
void emptyFunction98() {}
void emptyFunction99() {}
void emptyFunction100() {}
void emptyFunction101() {}
void emptyFunction102() {}
void emptyFunction103() {}
void emptyFunction104() {}
void emptyFunction105() {}
void emptyFunction106() {}
void emptyFunction107() {}
void emptyFunction108() {}
void emptyFunction109() {}
void emptyFunction110() {}
void emptyFunction111() {}
void emptyFunction112() {}
void emptyFunction113() {}
void emptyFunction114() {}
void emptyFunction115() {}
void emptyFunction116() {}
void emptyFunction117() {}
void emptyFunction118() {}
void emptyFunction119() {}
void emptyFunction120() {}
void emptyFunction121() {}
void emptyFunction122() {}
void emptyFunction123() {}
void emptyFunction124() {}
void emptyFunction125() {}
void emptyFunction126() {}
void emptyFunction127() {}
void emptyFunction128() {}
void emptyFunction129() {}
void emptyFunction130() {}
void emptyFunction131() {}
void emptyFunction132() {}
void emptyFunction133() {}
void emptyFunction134() {}
void emptyFunction135() {}
void emptyFunction136() {}
void emptyFunction137() {}
void emptyFunction138() {}
void emptyFunction139() {}
void emptyFunction140() {}
void emptyFunction141() {}
void emptyFunction142() {}
void emptyFunction143() {}
void emptyFunction144() {}
void emptyFunction145() {}
void emptyFunction146() {}
void emptyFunction147() {}
void emptyFunction148() {}
void emptyFunction149() {}
void emptyFunction150() {}
void emptyFunction151() {}
void emptyFunction152() {}
void emptyFunction153() {}
void emptyFunction154() {}
void emptyFunction155() {}
void emptyFunction156() {}
void emptyFunction157() {}
void emptyFunction158() {}
void emptyFunction159() {}
void emptyFunction160() {}
void emptyFunction161() {}
void emptyFunction162() {}
void emptyFunction163() {}
void emptyFunction164() {}
void emptyFunction165() {}
void emptyFunction166() {}
void emptyFunction167() {}
void emptyFunction168() {}
void emptyFunction169() {}
void emptyFunction170() {}
void emptyFunction171() {}
void emptyFunction172() {}
void emptyFunction173() {}
void emptyFunction174() {}
void emptyFunction175() {}
void emptyFunction176() {}
void emptyFunction177() {}
void emptyFunction178() {}
void emptyFunction179() {}
void emptyFunction180() {}
void emptyFunction181() {}
void emptyFunction182() {}
void emptyFunction183() {}
void emptyFunction184() {}
void emptyFunction185() {}
void emptyFunction186() {}
void emptyFunction187() {}
void emptyFunction188() {}
void emptyFunction189() {}
void emptyFunction190() {}
void emptyFunction191() {}
void emptyFunction192() {}
void emptyFunction193() {}
void emptyFunction194() {}
void emptyFunction195() {}
void emptyFunction196() {}
void emptyFunction197() {}
void emptyFunction198() {}
void emptyFunction199() {}
void emptyFunction200() {}
void emptyFunction201() {}
void emptyFunction202() {}
void emptyFunction203() {}
void emptyFunction204() {}
void emptyFunction205() {}
void emptyFunction206() {}
void emptyFunction207() {}
void emptyFunction208() {}
void emptyFunction209() {}
void emptyFunction210() {}
void emptyFunction211() {}
void emptyFunction212() {}
void emptyFunction213() {}
void emptyFunction214() {}
void emptyFunction215() {}
void emptyFunction216() {}
void emptyFunction217() {}
void emptyFunction218() {}
void emptyFunction219() {}
void emptyFunction220() {}
void emptyFunction221() {}
void emptyFunction222() {}
void emptyFunction223() {}
void emptyFunction224() {}
void emptyFunction225() {}
void emptyFunction226() {}
void emptyFunction227() {}
void emptyFunction228() {}
void emptyFunction229() {}
void emptyFunction230() {}
void emptyFunction231() {}
void emptyFunction232() {}
void emptyFunction233() {}
void emptyFunction234() {}
void emptyFunction235() {}
void emptyFunction236() {}
void emptyFunction237() {}
void emptyFunction238() {}
void emptyFunction239() {}
void emptyFunction240() {}
void emptyFunction241() {}
void emptyFunction242() {}
void emptyFunction243() {}
void emptyFunction244() {}
void emptyFunction245() {}
void emptyFunction246() {}
void emptyFunction247() {}
void emptyFunction248() {}
void emptyFunction249() {}
void emptyFunction250() {}
void emptyFunction251() {}
void emptyFunction252() {}
void emptyFunction253() {}
void emptyFunction254() {}
void emptyFunction255() {}
void emptyFunction256() {}
void emptyFunction257() {}
void emptyFunction258() {}
void emptyFunction259() {}
void emptyFunction260() {}
void emptyFunction261() {}
void emptyFunction262() {}
void emptyFunction263() {}
void emptyFunction264() {}
void emptyFunction265() {}
void emptyFunction266() {}
void emptyFunction267() {}
void emptyFunction268() {}
void emptyFunction269() {}
void emptyFunction270() {}
void emptyFunction271() {}
void emptyFunction272() {}
void emptyFunction273() {}
void emptyFunction274() {}
void emptyFunction275() {}
void emptyFunction276() {}
void emptyFunction277() {}
void emptyFunction278() {}
void emptyFunction279() {}
void emptyFunction280() {}
void emptyFunction281() {}
void emptyFunction282() {}
void emptyFunction283() {}
void emptyFunction284() {}
void emptyFunction285() {}
void emptyFunction286() {}
void emptyFunction287() {}
void emptyFunction288() {}
void emptyFunction289() {}
void emptyFunction290() {}
void emptyFunction291() {}
void emptyFunction292() {}
void emptyFunction293() {}
void emptyFunction294() {}
void emptyFunction295() {}
void emptyFunction296() {}
void emptyFunction297() {}
void emptyFunction298() {}
void emptyFunction299() {}
void emptyFunction300() {}
void emptyFunction301() {}
void emptyFunction302() {}
void emptyFunction303() {}
void emptyFunction304() {}
void emptyFunction305() {}
void emptyFunction306() {}
void emptyFunction307() {}
void emptyFunction308() {}
void emptyFunction309() {}
void emptyFunction310() {}
void emptyFunction311() {}
void emptyFunction312() {}
void emptyFunction313() {}
void emptyFunction314() {}
void emptyFunction315() {}
void emptyFunction316() {}
void emptyFunction317() {}
void emptyFunction318() {}
void emptyFunction319() {}
void emptyFunction320() {}
void emptyFunction321() {}
void emptyFunction322() {}
void emptyFunction323() {}
void emptyFunction324() {}
void emptyFunction325() {}
void emptyFunction326() {}
void emptyFunction327() {}
void emptyFunction328() {}
void emptyFunction329() {}
void emptyFunction330() {}
void emptyFunction331() {}
void emptyFunction332() {}
void emptyFunction333() {}
void emptyFunction334() {}
void emptyFunction335() {}
void emptyFunction336() {}
void emptyFunction337() {}
void emptyFunction338() {}
void emptyFunction339() {}
void emptyFunction340() {}
void emptyFunction341() {}
void emptyFunction342() {}
void emptyFunction343() {}
void emptyFunction344() {}
void emptyFunction345() {}
void emptyFunction346() {}
void emptyFunction347() {}
void emptyFunction348() {}
void emptyFunction349() {}
void emptyFunction350() {}
void emptyFunction351() {}
void emptyFunction352() {}
void emptyFunction353() {}
void emptyFunction354() {}
void emptyFunction355() {}
void emptyFunction356() {}
void emptyFunction357() {}
void emptyFunction358() {}
void emptyFunction359() {}
void emptyFunction360() {}
void emptyFunction361() {}
void emptyFunction362() {}
void emptyFunction363() {}
void emptyFunction364() {}
void emptyFunction365() {}
void emptyFunction366() {}
void emptyFunction367() {}
void emptyFunction368() {}
void emptyFunction369() {}
void emptyFunction370() {}
void emptyFunction371() {}
void emptyFunction372() {}
void emptyFunction373() {}
void emptyFunction374() {}
void emptyFunction375() {}
void emptyFunction376() {}
void emptyFunction377() {}
void emptyFunction378() {}
void emptyFunction379() {}
void emptyFunction380() {}
void emptyFunction381() {}
void emptyFunction382() {}
void emptyFunction383() {}
void emptyFunction384() {}
void emptyFunction385() {}
void emptyFunction386() {}
void emptyFunction387() {}
void emptyFunction388() {}
void emptyFunction389() {}
void emptyFunction390() {}
void emptyFunction391() {}
void emptyFunction392() {}
void emptyFunction393() {}
void emptyFunction394() {}
void emptyFunction395() {}
void emptyFunction396() {}
void emptyFunction397() {}
void emptyFunction398() {}
void emptyFunction399() {}
void emptyFunction400() {}
void emptyFunction401() {}
void emptyFunction402() {}
void emptyFunction403() {}
void emptyFunction404() {}
void emptyFunction405() {}
void emptyFunction406() {}
void emptyFunction407() {}
void emptyFunction408() {}
void emptyFunction409() {}
void emptyFunction410() {}
void emptyFunction411() {}
void emptyFunction412() {}
void emptyFunction413() {}
void emptyFunction414() {}
void emptyFunction415() {}
void emptyFunction416() {}
void emptyFunction417() {}
void emptyFunction418() {}
void emptyFunction419() {}
void emptyFunction420() {}
void emptyFunction421() {}
void emptyFunction422() {}
void emptyFunction423() {}
void emptyFunction424() {}
void emptyFunction425() {}
void emptyFunction426() {}
void emptyFunction427() {}
void emptyFunction428() {}
void emptyFunction429() {}
void emptyFunction430() {}
void emptyFunction431() {}
void emptyFunction432() {}
void emptyFunction433() {}
void emptyFunction434() {}
void emptyFunction435() {}
void emptyFunction436() {}
void emptyFunction437() {}
void emptyFunction438() {}
void emptyFunction439() {}
void emptyFunction440() {}
void emptyFunction441() {}
void emptyFunction442() {}
void emptyFunction443() {}
void emptyFunction444() {}
void emptyFunction445() {}
void emptyFunction446() {}
void emptyFunction447() {}
void emptyFunction448() {}
void emptyFunction449() {}
void emptyFunction450() {}
void emptyFunction451() {}
void emptyFunction452() {}
void emptyFunction453() {}
void emptyFunction454() {}
void emptyFunction455() {}
void emptyFunction456() {}
void emptyFunction457() {}
void emptyFunction458() {}
void emptyFunction459() {}
void emptyFunction460() {}
void emptyFunction461() {}
void emptyFunction462() {}
void emptyFunction463() {}
void emptyFunction464() {}
void emptyFunction465() {}
void emptyFunction466() {}
void emptyFunction467() {}
void emptyFunction468() {}
void emptyFunction469() {}
void emptyFunction470() {}
void emptyFunction471() {}
void emptyFunction472() {}
void emptyFunction473() {}
void emptyFunction474() {}
void emptyFunction475() {}
void emptyFunction476() {}
void emptyFunction477() {}
void emptyFunction478() {}
void emptyFunction479() {}
void emptyFunction480() {}
void emptyFunction481() {}
void emptyFunction482() {}
void emptyFunction483() {}
void emptyFunction484() {}
void emptyFunction485() {}
void emptyFunction486() {}
void emptyFunction487() {}
void emptyFunction488() {}
void emptyFunction489() {}
void emptyFunction490() {}
void emptyFunction491() {}
void emptyFunction492() {}
void emptyFunction493() {}
void emptyFunction494() {}
void emptyFunction495() {}
void emptyFunction496() {}
void emptyFunction497() {}
void emptyFunction498() {}
void emptyFunction499() {}
void emptyFunction500() {}
void emptyFunction501() {}
void emptyFunction502() {}
void emptyFunction503() {}
void emptyFunction504() {}
void emptyFunction505() {}
void emptyFunction506() {}
void emptyFunction507() {}
void emptyFunction508() {}
void emptyFunction509() {}
void emptyFunction510() {}
void emptyFunction511() {}
void emptyFunction512() {}
void emptyFunction513() {}
void emptyFunction514() {}
void emptyFunction515() {}
void emptyFunction516() {}
void emptyFunction517() {}
void emptyFunction518() {}
void emptyFunction519() {}
void emptyFunction520() {}
void emptyFunction521() {}
void emptyFunction522() {}
void emptyFunction523() {}
void emptyFunction524() {}
void emptyFunction525() {}
void emptyFunction526() {}
void emptyFunction527() {}
void emptyFunction528() {}
void emptyFunction529() {}
void emptyFunction530() {}
void emptyFunction531() {}
void emptyFunction532() {}
void emptyFunction533() {}
void emptyFunction534() {}
void emptyFunction535() {}
void emptyFunction536() {}
void emptyFunction537() {}
void emptyFunction538() {}
void emptyFunction539() {}
void emptyFunction540() {}
void emptyFunction541() {}
void emptyFunction542() {}
void emptyFunction543() {}
void emptyFunction544() {}
void emptyFunction545() {}
void emptyFunction546() {}
void emptyFunction547() {}
void emptyFunction548() {}
void emptyFunction549() {}
void emptyFunction550() {}
void emptyFunction551() {}
void emptyFunction552() {}
void emptyFunction553() {}
void emptyFunction554() {}
void emptyFunction555() {}
void emptyFunction556() {}
void emptyFunction557() {}
void emptyFunction558() {}
void emptyFunction559() {}
void emptyFunction560() {}
void emptyFunction561() {}
void emptyFunction562() {}
void emptyFunction563() {}
void emptyFunction564() {}
void emptyFunction565() {}
void emptyFunction566() {}
void emptyFunction567() {}
void emptyFunction568() {}
void emptyFunction569() {}
void emptyFunction570() {}
void emptyFunction571() {}
void emptyFunction572() {}
void emptyFunction573() {}
void emptyFunction574() {}
void emptyFunction575() {}
void emptyFunction576() {}
void emptyFunction577() {}
void emptyFunction578() {}
void emptyFunction579() {}
void emptyFunction580() {}
void emptyFunction581() {}
void emptyFunction582() {}
void emptyFunction583() {}
void emptyFunction584() {}
void emptyFunction585() {}
void emptyFunction586() {}
void emptyFunction587() {}
void emptyFunction588() {}
void emptyFunction589() {}
void emptyFunction590() {}
void emptyFunction591() {}
void emptyFunction592() {}
void emptyFunction593() {}
void emptyFunction594() {}
void emptyFunction595() {}
void emptyFunction596() {}
void emptyFunction597() {}
void emptyFunction598() {}
void emptyFunction599() {}
void emptyFunction600() {}
void emptyFunction601() {}
void emptyFunction602() {}
void emptyFunction603() {}
void emptyFunction604() {}
void emptyFunction605() {}
void emptyFunction606() {}
void emptyFunction607() {}
void emptyFunction608() {}
void emptyFunction609() {}
void emptyFunction610() {}
void emptyFunction611() {}
void emptyFunction612() {}
void emptyFunction613() {}
void emptyFunction614() {}
void emptyFunction615() {}
void emptyFunction616() {}
void emptyFunction617() {}
void emptyFunction618() {}
void emptyFunction619() {}
void emptyFunction620() {}
void emptyFunction621() {}
void emptyFunction622() {}
void emptyFunction623() {}
void emptyFunction624() {}
void emptyFunction625() {}
void emptyFunction626() {}
void emptyFunction627() {}
void emptyFunction628() {}
void emptyFunction629() {}
void emptyFunction630() {}
void emptyFunction631() {}
void emptyFunction632() {}
void emptyFunction633() {}
void emptyFunction634() {}
void emptyFunction635() {}
void emptyFunction636() {}
void emptyFunction637() {}
void emptyFunction638() {}
void emptyFunction639() {}
void emptyFunction640() {}
void emptyFunction641() {}
void emptyFunction642() {}
void emptyFunction643() {}
void emptyFunction644() {}
void emptyFunction645() {}
void emptyFunction646() {}
void emptyFunction647() {}
void emptyFunction648() {}
void emptyFunction649() {}
void emptyFunction650() {}
void emptyFunction651() {}
void emptyFunction652() {}
void emptyFunction653() {}
void emptyFunction654() {}
void emptyFunction655() {}
void emptyFunction656() {}
void emptyFunction657() {}
void emptyFunction658() {}
void emptyFunction659() {}
void emptyFunction660() {}
void emptyFunction661() {}
void emptyFunction662() {}
void emptyFunction663() {}
void emptyFunction664() {}
void emptyFunction665() {}
void emptyFunction666() {}
void emptyFunction667() {}
void emptyFunction668() {}
void emptyFunction669() {}
void emptyFunction670() {}
void emptyFunction671() {}
void emptyFunction672() {}
void emptyFunction673() {}
void emptyFunction674() {}
void emptyFunction675() {}
void emptyFunction676() {}
void emptyFunction677() {}
void emptyFunction678() {}
void emptyFunction679() {}
void emptyFunction680() {}
void emptyFunction681() {}
void emptyFunction682() {}
void emptyFunction683() {}
void emptyFunction684() {}
void emptyFunction685() {}
void emptyFunction686() {}
void emptyFunction687() {}
void emptyFunction688() {}
void emptyFunction689() {}
void emptyFunction690() {}
void emptyFunction691() {}
void emptyFunction692() {}
void emptyFunction693() {}
void emptyFunction694() {}
void emptyFunction695() {}
void emptyFunction696() {}
void emptyFunction697() {}
void emptyFunction698() {}
void emptyFunction699() {}
void emptyFunction700() {}
void emptyFunction701() {}
void emptyFunction702() {}
void emptyFunction703() {}
void emptyFunction704() {}
void emptyFunction705() {}
void emptyFunction706() {}
void emptyFunction707() {}
void emptyFunction708() {}
void emptyFunction709() {}
void emptyFunction710() {}
void emptyFunction711() {}
void emptyFunction712() {}
void emptyFunction713() {}
void emptyFunction714() {}
void emptyFunction715() {}
void emptyFunction716() {}
void emptyFunction717() {}
void emptyFunction718() {}
void emptyFunction719() {}
void emptyFunction720() {}
void emptyFunction721() {}
void emptyFunction722() {}
void emptyFunction723() {}
void emptyFunction724() {}
void emptyFunction725() {}
void emptyFunction726() {}
void emptyFunction727() {}
void emptyFunction728() {}
void emptyFunction729() {}
void emptyFunction730() {}
void emptyFunction731() {}
void emptyFunction732() {}
void emptyFunction733() {}
void emptyFunction734() {}
void emptyFunction735() {}
void emptyFunction736() {}
void emptyFunction737() {}
void emptyFunction738() {}
void emptyFunction739() {}
void emptyFunction740() {}
void emptyFunction741() {}
void emptyFunction742() {}
void emptyFunction743() {}
void emptyFunction744() {}
void emptyFunction745() {}
void emptyFunction746() {}
void emptyFunction747() {}
void emptyFunction748() {}
void emptyFunction749() {}
void emptyFunction750() {}
void emptyFunction751() {}
void emptyFunction752() {}
void emptyFunction753() {}
void emptyFunction754() {}
void emptyFunction755() {}
void emptyFunction756() {}
void emptyFunction757() {}
void emptyFunction758() {}
void emptyFunction759() {}
void emptyFunction760() {}
void emptyFunction761() {}
void emptyFunction762() {}
void emptyFunction763() {}
void emptyFunction764() {}
void emptyFunction765() {}
void emptyFunction766() {}
void emptyFunction767() {}
void emptyFunction768() {}
void emptyFunction769() {}
void emptyFunction770() {}
void emptyFunction771() {}
void emptyFunction772() {}
void emptyFunction773() {}
void emptyFunction774() {}
void emptyFunction775() {}
void emptyFunction776() {}
void emptyFunction777() {}
void emptyFunction778() {}
void emptyFunction779() {}
void emptyFunction780() {}
void emptyFunction781() {}
void emptyFunction782() {}
void emptyFunction783() {}
void emptyFunction784() {}
void emptyFunction785() {}
void emptyFunction786() {}
void emptyFunction787() {}
void emptyFunction788() {}
void emptyFunction789() {}
void emptyFunction790() {}
void emptyFunction791() {}
void emptyFunction792() {}
void emptyFunction793() {}
void emptyFunction794() {}
void emptyFunction795() {}
void emptyFunction796() {}
void emptyFunction797() {}
void emptyFunction798() {}
void emptyFunction799() {}
void emptyFunction800() {}
void emptyFunction801() {}
void emptyFunction802() {}
void emptyFunction803() {}
void emptyFunction804() {}
void emptyFunction805() {}
void emptyFunction806() {}
void emptyFunction807() {}
void emptyFunction808() {}
void emptyFunction809() {}
void emptyFunction810() {}
void emptyFunction811() {}
void emptyFunction812() {}
void emptyFunction813() {}
void emptyFunction814() {}
void emptyFunction815() {}
void emptyFunction816() {}
void emptyFunction817() {}
void emptyFunction818() {}
void emptyFunction819() {}
void emptyFunction820() {}
void emptyFunction821() {}
void emptyFunction822() {}
void emptyFunction823() {}
void emptyFunction824() {}
void emptyFunction825() {}
void emptyFunction826() {}
void emptyFunction827() {}
void emptyFunction828() {}
void emptyFunction829() {}
void emptyFunction830() {}
void emptyFunction831() {}
void emptyFunction832() {}
void emptyFunction833() {}
void emptyFunction834() {}
void emptyFunction835() {}
void emptyFunction836() {}
void emptyFunction837() {}
void emptyFunction838() {}
void emptyFunction839() {}
void emptyFunction840() {}
void emptyFunction841() {}
void emptyFunction842() {}
void emptyFunction843() {}
void emptyFunction844() {}
void emptyFunction845() {}
void emptyFunction846() {}
void emptyFunction847() {}
void emptyFunction848() {}
void emptyFunction849() {}
void emptyFunction850() {}
void emptyFunction851() {}
void emptyFunction852() {}
void emptyFunction853() {}
void emptyFunction854() {}
void emptyFunction855() {}
void emptyFunction856() {}
void emptyFunction857() {}
void emptyFunction858() {}
void emptyFunction859() {}
void emptyFunction860() {}
void emptyFunction861() {}
void emptyFunction862() {}
void emptyFunction863() {}
void emptyFunction864() {}
void emptyFunction865() {}
void emptyFunction866() {}
void emptyFunction867() {}
void emptyFunction868() {}
void emptyFunction869() {}
void emptyFunction870() {}
void emptyFunction871() {}
void emptyFunction872() {}
void emptyFunction873() {}
void emptyFunction874() {}
void emptyFunction875() {}
void emptyFunction876() {}
void emptyFunction877() {}
void emptyFunction878() {}
void emptyFunction879() {}
void emptyFunction880() {}
void emptyFunction881() {}
void emptyFunction882() {}
void emptyFunction883() {}
void emptyFunction884() {}
void emptyFunction885() {}
void emptyFunction886() {}
void emptyFunction887() {}
void emptyFunction888() {}
void emptyFunction889() {}
void emptyFunction890() {}
void emptyFunction891() {}
void emptyFunction892() {}
void emptyFunction893() {}
void emptyFunction894() {}
void emptyFunction895() {}
void emptyFunction896() {}
void emptyFunction897() {}
void emptyFunction898() {}
void emptyFunction899() {}
void emptyFunction900() {}
void emptyFunction901() {}
void emptyFunction902() {}
void emptyFunction903() {}
void emptyFunction904() {}
void emptyFunction905() {}
void emptyFunction906() {}
void emptyFunction907() {}
void emptyFunction908() {}
void emptyFunction909() {}
void emptyFunction910() {}
void emptyFunction911() {}
void emptyFunction912() {}
void emptyFunction913() {}
void emptyFunction914() {}
void emptyFunction915() {}
void emptyFunction916() {}
void emptyFunction917() {}
void emptyFunction918() {}
void emptyFunction919() {}
void emptyFunction920() {}
void emptyFunction921() {}
void emptyFunction922() {}
void emptyFunction923() {}
void emptyFunction924() {}
void emptyFunction925() {}
void emptyFunction926() {}
void emptyFunction927() {}
void emptyFunction928() {}
void emptyFunction929() {}
void emptyFunction930() {}
void emptyFunction931() {}
void emptyFunction932() {}
void emptyFunction933() {}
void emptyFunction934() {}
void emptyFunction935() {}
void emptyFunction936() {}
void emptyFunction937() {}
void emptyFunction938() {}
void emptyFunction939() {}
void emptyFunction940() {}
void emptyFunction941() {}
void emptyFunction942() {}
void emptyFunction943() {}
void emptyFunction944() {}
void emptyFunction945() {}
void emptyFunction946() {}
void emptyFunction947() {}
void emptyFunction948() {}
void emptyFunction949() {}
void emptyFunction950() {}
void emptyFunction951() {}
void emptyFunction952() {}
void emptyFunction953() {}
void emptyFunction954() {}
void emptyFunction955() {}
void emptyFunction956() {}
void emptyFunction957() {}
void emptyFunction958() {}
void emptyFunction959() {}
void emptyFunction960() {}
void emptyFunction961() {}
void emptyFunction962() {}
void emptyFunction963() {}
void emptyFunction964() {}
void emptyFunction965() {}
void emptyFunction966() {}
void emptyFunction967() {}
void emptyFunction968() {}
void emptyFunction969() {}
void emptyFunction970() {}
void emptyFunction971() {}
void emptyFunction972() {}
void emptyFunction973() {}
void emptyFunction974() {}
void emptyFunction975() {}
void emptyFunction976() {}
void emptyFunction977() {}
void emptyFunction978() {}
void emptyFunction979() {}
void emptyFunction980() {}
void emptyFunction981() {}
void emptyFunction982() {}
void emptyFunction983() {}
void emptyFunction984() {}
void emptyFunction985() {}
void emptyFunction986() {}
void emptyFunction987() {}
void emptyFunction988() {}
void emptyFunction989() {}
void emptyFunction990() {}
void emptyFunction991() {}
void emptyFunction992() {}
void emptyFunction993() {}
void emptyFunction994() {}
void emptyFunction995() {}
void emptyFunction996() {}
void emptyFunction997() {}
void emptyFunction998() {}
void emptyFunction999() {}
void emptyFunction1000() {}

END_NAMESPACE

int main() {
    using namespace crap;
    srand(time(nullptr));
    MoneyManager manager;
    for (int i = 1; i <= TOTAL_MONEY; ++i) {
        for (int j = 1; j <= TOTAL_MONEY - i; ++j) {
            int k = TOTAL_MONEY - i - j;
            if (k <= 0) continue;
            manager.setInitial(i, j, k);
            manager.distribute("A");
            manager.distribute("B");
            manager.distribute("C");
            if (manager.isFinal()) {
                std::cout << i << " " << j << " " << k << std::endl;
                return 0;
            }
        }
    }
    return -1;
}