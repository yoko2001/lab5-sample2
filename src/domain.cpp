#include "domain.h"
int domain::domain_id = 0; //初始化

domain* born_son_domain(domain* fa){
    domain* son = new domain(0, 0, block_domain);
    son->set_f_domain(fa);
    fa->add_s_domain(son);
    son->depth = fa->depth+1;
    return son;
}


/**
 * this is really ugly. but I'm such a tired lazy dog
 * who doesn't want to provide a sub-linear algorithm, 
 * and also doesn't want use std::map either, because 
 * that's also ugly (in another way), should use hash
 * + bucket that kind of stuff
 */
domain_elem* _LookupSymple(domain* dm, std::string name, bool searchOuter){
    domain* cur_dm = dm;
    while(cur_dm){
        for(std::vector<domain_elem>::iterator iter = cur_dm->elements.begin(); iter != cur_dm->elements.end(); iter++){
            if (iter->s == name){
                return &(*iter);
            }
        }
        // check if father domain has it
        cur_dm = cur_dm->father_domain;
    }
    return NULL;
}
/**
 * search for the name from current domain, 
 * and all outer domains, return the nearest
 */
domain_elem* LookupID(domain* dm, std::string name){
    return _LookupSymple(dm, name, 1);
}