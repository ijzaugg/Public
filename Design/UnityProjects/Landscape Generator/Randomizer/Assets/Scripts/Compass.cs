using UnityEngine;

public class Compass : MonoBehaviour
{
    public Transform player;               // The player object
    public Transform flag;                 // The flag target
    public RectTransform compassNeedle;    // The UI arrow image

    void Update()
    {
        // Get the direction to the flag, flattened to horizontal plane
        Vector3 directionToFlag = flag.position - player.position;
        directionToFlag.y = 0f;
        directionToFlag.Normalize();

        // Get the forward direction of the player (flattened)
        Vector3 playerForward = player.forward;
        playerForward.y = 0f;
        playerForward.Normalize();

        // Calculate the signed angle between forward and flag direction
        float angle = Vector3.SignedAngle(playerForward, directionToFlag, Vector3.up);

        // Rotate the compass needle in UI
        compassNeedle.localEulerAngles = new Vector3(0, 0, -angle);
    }
}
