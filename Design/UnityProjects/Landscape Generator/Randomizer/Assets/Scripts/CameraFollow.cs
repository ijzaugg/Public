using UnityEngine;

public class CameraFollow : MonoBehaviour
{
    public Transform target;        // The player
    public Vector3 offset = new Vector3(0f, 10f, -10f); // Height and behind
    public float smoothSpeed = 5f;  // Camera movement smoothness

    void LateUpdate()
    {
        if (target == null) return;

        Vector3 desiredPosition = target.position + offset;
        Vector3 smoothedPosition = Vector3.Lerp(transform.position, desiredPosition, smoothSpeed * Time.deltaTime);

        transform.position = smoothedPosition;
        transform.LookAt(target); // Optional: always look at the player
    }
}
