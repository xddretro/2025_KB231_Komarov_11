#ifndef SMART_PTR_HPP
#define SMART_PTR_HPP

template <typename T>
class smart_ptr {
    T* obj;
public:
    explicit smart_ptr(T* obj = nullptr) : obj(obj) {}
    ~smart_ptr() { delete obj; }

    T* operator->() { return obj; }
    T& operator*() { return *obj; }

    // Запрет копирования
    smart_ptr(const smart_ptr&) = delete;
    smart_ptr& operator=(const smart_ptr&) = delete;

    // Разрешить перемещение
    smart_ptr(smart_ptr&& other) noexcept : obj(other.obj) {
        other.obj = nullptr;
    }

    smart_ptr& operator=(smart_ptr&& other) noexcept {
        if (this != &other) {
            delete obj;
            obj = other.obj;
            other.obj = nullptr;
        }
        return *this;
    }
};

#endif // SMART_PTR_HPP
