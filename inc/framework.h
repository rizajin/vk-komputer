#ifndef KOMPUTE_FRAMEWORK
#define KOMPUTE_FRAMEWORK

class KomputeFramework
{
   public:
    KomputeFramework() = default;
    ~KomputeFramework();
    bool Init();
    
   private:
    void CleanUp();
};

#endif
