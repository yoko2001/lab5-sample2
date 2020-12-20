#include "domain.h"
int domain::domain_id = 0; //初始化

domain* born_son_domain(domain* fa){
    domain* son = new domain(0, 0, block_domain);
    son->set_f_domain(fa);
    fa->add_s_domain(son);
    son->depth = fa->depth+1;
    return son;
}
