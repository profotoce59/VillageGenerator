#pragma once

#include <vector>
#include <string>

struct TemplateEntry {
    std::string name;
    int weight;

    TemplateEntry(const std::string& name, int weight)
        : name(name), weight(weight) {}
};

struct JigSawPool {
  std::vector<std::string> names;
  std::vector<uint32_t>    index_flat;
};

JigSawPool make_pool(const std::vector<TemplateEntry>& tpl);