package com.example.myapplication

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import com.example.myapplication.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.sampleText.text = getText()
    }

    private fun getText(): String
    {
        val lib1 = createLib1()
        val lib2 = createLib2()

        val methodList1 = getMethodLists(lib1)
        val methodList2 = getMethodLists(lib2)

        val methods1 = methodList1.joinToString(separator = ", ")
        val methods2 = methodList2.joinToString(separator = ", ")

        return "$methods1; $methods2"
    }

    /**
     * A native method that is implemented by the 'myapplication' native library,
     * which is packaged with this application.
     */
    external fun createLib1(): Long
    external fun createLib2(): Long
    external fun getMethodLists(ptr: Long): List<String>

    companion object {
        // Used to load the 'myapplication' library on application startup.
        init {
            System.loadLibrary("myapplication")
            System.loadLibrary("shared1")
            System.loadLibrary("shared2")
        }
    }
}