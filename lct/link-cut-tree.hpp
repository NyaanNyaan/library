#pragma once

#include "splay-reversible.hpp"

//
#include "link-cut-base.hpp"

template <typename T, T (*f)(T, T), T (*ts)(T)>
struct LinkCutTree : LinkCutBase<ReversibleSplayTree<T, f, ts>> {};

/**
 * @brief Link/Cut Tree
 * @docs docs/lct/link-cut-tree.md
 */
