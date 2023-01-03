### static member var vs static member function
static member var can be access any of instace. even class name it self can access

# about static member var and static member function
https://musket-ade.tistory.com/32


### typedef
typedef vector<Account::t>	accounts_t
typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

### iterator

### vertor constructor
위에서 설명한 생성자들을 차례대로 오버로딩함 
vector<int> first; int 를 보관할 빈벡터 생성    
vector<int> second (4,100); // 값이 100 인 int 원소 4 개 보관    
vector<int> third(second.begin(),second.end());  // second 의 처음 ~ 끝으로
vector<int> fourth (third); // 세 번째 벡터 복사본

// 배열을 통해서도 생성 가능하다.
int myints[] = {16, 2, 77, 29};
vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

### iterator with pair

### for_each, mem_fun_ref

### access object with iterator "*(iter) = object"
