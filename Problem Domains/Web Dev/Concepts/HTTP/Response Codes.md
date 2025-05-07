# Response Codes

Responses from the server contain status codes to alert the client to information about the success of the operation. As a developer, you do not need to know every status code (there are many of them), but you should know the most common ones and how they are used:

Here's your information formatted as a GitHub Markdown table:


| Status Code                 |Meaning |
|-----------------------------|---------------------------------------------------------------------------------------------|
| 200 (OK)                    | This is the standard response for successful HTTP requests.                                 |
| 201 (CREATED)               | This is the standard response for an HTTP request that resulted in an item being successfully created. |
| 204 (NO CONTENT)            | This is the standard response for successful HTTP requests, where nothing is being returned in the response body. |
| 400 (BAD REQUEST)           | The request cannot be processed because of bad request syntax, excessive size, or another client error. |
| 403 (FORBIDDEN)             | The client does not have permission to access this resource.                                |
| 404 (NOT FOUND)             | The resource could not be found at this time. It is possible it was deleted, or does not exist yet. |
| 500 (INTERNAL SERVER ERROR) | The generic answer for an unexpected failure if there is no more specific information available. |

Would you like a rendered preview of how this looks?


For each HTTP verb, there are expected status codes a server should return upon success:

    GET — return 200 (OK)
    POST — return 201 (CREATED)
    PUT — return 200 (OK)
    DELETE — return 204 (NO CONTENT) If the operation fails, return the most specific status code possible corresponding to the problem that was encountered.
