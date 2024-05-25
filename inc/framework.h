#ifndef KOMPUTE_FRAMEWORK
#define KOMPUTE_FRAMEWORK

class KomputeFramework
{
   public:
    KomputeFramework() = default;
    ~KomputeFramework();
    bool Init();

    KomputeFramework(const KomputeFramework&) = delete;
    KomputeFramework& operator=(const KomputeFramework&) = delete;
    KomputeFramework(KomputeFramework&&) = delete;
    KomputeFramework& operator=(KomputeFramework&&) = delete;
   private:
    void CleanUp();
};

#endif
