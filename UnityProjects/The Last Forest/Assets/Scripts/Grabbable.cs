using UnityEngine;

public class Grabbable : MonoBehaviour
{
    public bool isGrabbed = false;

    // Method called when the object is grabbed
    public void Grab()
    {
        isGrabbed = true;
        // Add any additional logic you need when the object is grabbed, such as disabling physics, changing appearance, etc.
    }

    // Method called when the object is released
    public void Release()
    {
        isGrabbed = false;
        // Add any additional logic you need when the object is released, such as enabling physics, resetting appearance, etc.
    }
}
