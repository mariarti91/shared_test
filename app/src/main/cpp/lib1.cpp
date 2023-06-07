#include "ISharedLibrary.h"

#include <jni.h>

#include "Shared.h"

namespace test::lib
{

using namespace std::string_literals;

namespace
{

class SharedLib : public test::lib::ILoadedLibrary
{
public:
    std::vector<std::string> get_method_lists() override
    {
        static const int id = 0;
        return test::lib::shared::get_data(id);
    };
};

} // namespace

extern "C" JNIEXPORT jlong JNICALL
Java_com_example_myapplication_MainActivity_createLib1(
        JNIEnv* /* env */,
        jobject /* this */)
{
    test::lib::ILoadedLibrary * res = new test::lib::SharedLib{};
    return reinterpret_cast<jlong>(res);
}

} // namespace test::lib