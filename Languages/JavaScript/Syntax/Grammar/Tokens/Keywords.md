## Keywords

Keywords are tokens that look like identifiers but have special meanings in JavaScript. For example, the keyword async before a function declaration indicates that the function is asynchronous.

Some keywords are reserved, meaning that they cannot be used as an identifier for variable declarations, function declarations, etc. They are often called reserved words. A list of these reserved words is provided below. Not all keywords are reserved — for example, async can be used as an identifier anywhere. Some keywords are only contextually reserved — for example, await is only reserved within the body of an async function, and let is only reserved in strict mode code, or const and let declarations.

Identifiers are always compared by string value, so escape sequences are interpreted. For example, this is still a syntax error:
js

const els\u{65} = 1;
// `els\u{65}` encodes the same identifier as `else`

### Reserved words

These keywords cannot be used as identifiers for variables, functions, classes, etc. anywhere in JavaScript source.

    break
    case
    catch
    class
    const
    continue
    debugger
    default
    delete
    do
    else
    export
    extends
    false
    finally
    for
    function
    if
    import
    in
    instanceof
    new
    null
    return
    super
    switch
    this
    throw
    true
    try
    typeof
    var
    void
    while
    with

The following are only reserved when they are found in strict mode code:

    let (also reserved in const, let, and class declarations)
    static
    yield (also reserved in generator function bodies)

The following are only reserved when they are found in module code or async function bodies:

    await

### Future reserved words

The following are reserved as future keywords by the ECMAScript specification. They have no special functionality at present, but they might at some future time, so they cannot be used as identifiers.

These are always reserved:

    enum

The following are only reserved when they are found in strict mode code:

    implements
    interface
    package
    private
    protected
    public

Future reserved words in older standards

The following are reserved as future keywords by older ECMAScript specifications (ECMAScript 1 till 3).

    abstract
    boolean
    byte
    char
    double
    final
    float
    goto
    int
    long
    native
    short
    synchronized
    throws
    transient
    volatile

### Identifiers with special meanings

A few identifiers have a special meaning in some contexts without being reserved words of any kind. They include:

    arguments (not a keyword, but cannot be declared as identifier in strict mode)
    as (import * as ns from "mod")
    async
    eval (not a keyword, but cannot be declared as identifier in strict mode)
    from (import x from "mod")
    get
    of
    set