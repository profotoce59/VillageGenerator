#pragma once

#include <vector>
#include <string_view>

struct TemplateEntry {
    std::string_view name;
    int weight;

    TemplateEntry(std::string_view name, int weight)
        : name(name), weight(weight) {}
};

struct JigSawPool {
  std::vector<std::string_view> names;
  std::vector<uint32_t>    index_flat;
};

JigSawPool make_pool(const std::vector<TemplateEntry>& tpl);
