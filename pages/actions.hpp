#ifndef PAGES_ACTIONS_HPP
#define PAGES_ACTIONS_HPP

#include <memory>
#include <variant>

class Page;

struct NavigateAction { int index; };
struct ReplaceAction { std::unique_ptr<Page> page; };
struct PushAction { std::unique_ptr<Page> page; };
struct PopAction { std::unique_ptr<Page> page; };

using PageActionResult = std::variant<std::monostate, 
                                        NavigateAction,
                                        ReplaceAction,
                                        PushAction,
                                        PopAction>;

#endif // PAGES_ACTIONS_HPP