#include <algorithm>

void f(vector<Entry>&vec, list<Entry>&lst){
    std::sort(vec.begin(), vec.end()); //usr < for order
    std::unique_copy(vec.begin(), vec.end(), lst.begin()) //ne copie pas les adjacent equal elements
}

bool operator<(const Entry&x, constEntry&y){
    return x.name<y.name;
}


void test(){
    std::string m {"Mary had a little lamb"};
    for(auto p : std::find_all(m,'a')){
        if(*p!='a') std::cerr << "a bug!\n";
    }
}

//overview
for_each(b,e,f); //for each elements x in [b:e), do f(x)
p=find(b,e,x); // p est le premier p dans [b:e) tel que *p == x
p=find(b,e,f); // p est le premier p dans [b:e) tel que f(*p)
n=count(b,e,x); // n est le nombre d'élements q dans [b:e) tel que *q==x
n=count_if(b,e,f);
replace(b,e,v,v2); //replace v par v2
replace_if(b,e,v,v2,f);
copy(b,e,out);
copy_if(b,e,out);
move(b,e,out);
unique_copy(b,e,out);
sort(b,e);
sort(b,e,f);
merge(b,e,b2,e2,out);
merge(b,e,b2,e2,out,f);
