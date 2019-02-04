
//parent class
struct base{
    int a ;
    void (*func1)(struct base* _this);

};

//children class
struct derived{
    struct base parent;
    int b;
    void (*func2)(struct derived* _this);
};


struct base * new_base();

struct derived * new_derived();

static void base_func1(struct base * self);

static void derived_func2(struct derived * self);

