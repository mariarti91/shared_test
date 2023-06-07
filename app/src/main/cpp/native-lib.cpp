#include <jni.h>
#include <string>

#include "ISharedLibrary.h"

extern "C"
JNIEXPORT jobject JNICALL
Java_com_example_myapplication_MainActivity_getMethodLists(JNIEnv * env, jobject/* thiz */, jlong jptr)
{
    const auto methods_list = [&]
    {
        auto * lib = reinterpret_cast<test::lib::ILoadedLibrary*>(jptr);
        return lib->get_method_lists();
    }();

    jclass vectorClass = env->FindClass("java/util/Vector");
    jmethodID vectorConstructorID = env->GetMethodID(
            vectorClass, "<init>", "()V");
    jmethodID addMethodID = env->GetMethodID(
            vectorClass, "add", "(Ljava/lang/Object;)Z" );

    jobject outerVector = env->NewObject(vectorClass, vectorConstructorID);

    for (const auto & m : methods_list)
    {
        auto jm = env->NewStringUTF(m.c_str());
        env->CallBooleanMethod(outerVector, addMethodID, jm);
    }

    env->DeleteLocalRef(vectorClass);

    return outerVector;
}