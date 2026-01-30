#include "JigSawPool.hpp"

// JigSawPool.cpp
JigSawPool make_pool(const std::vector<TemplateEntry>& tpl) {
    JigSawPool p;
    p.names.reserve(tpl.size());
    size_t total = 0;
    for (auto& t : tpl) { p.names.push_back(t.name); total += (size_t)t.weight; }
    p.index_flat.reserve(total);
    for (int i = 0; i < (int)tpl.size(); ++i)
        for (int k = 0; k < tpl[i].weight; ++k)
            p.index_flat.push_back(i);
    return p;
}