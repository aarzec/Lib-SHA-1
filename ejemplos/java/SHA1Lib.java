package ejemplos.java;

public class SHA1Lib {
    public native void sha1_hash(String input, byte[] output);
    static {
        System.loadLibrary("sha1");
    }
}
