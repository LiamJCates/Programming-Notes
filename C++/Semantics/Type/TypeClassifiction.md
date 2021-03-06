Objects, references, functions including function template specializations, and expressions have a property called type, which both restricts the operations that are permitted for those entities and provides semantic meaning to the otherwise generic sequences of bits.



Type classification

The C++ type system consists of the following types:

	Fundamental Types
		void
		nullptr (C++11)

		Arithmetic Types

			Floating-Point Types
				float
				double
				long double

			Integral Types
				bool

				Character Types

					Narrow Character Types
						char (signed/unsigned)
						char8_t (C++20)

					Wide Character Types
						wchar_t
						char16_t (C++11)
						char32_t (C++11)

				Integer Types	(signed/unsigned)
					short int		
					int
					long int
					long long int

	Compound Types

		Reference Type
			Lvalue Reference Types
				lvalue reference to object
				lvalue reference to function

			Rvalue Reference Types
				rvalue reference to object
				rvalue reference to function

		Pointer Types
			pointer-to-object
			pointer-to-function

		Pointer-to-Member Types
			pointer-to-data-member
			pointer-to-member-function  

		Array

		Function

		Enumeration

		Class types
			non-union
			union

For every type other than reference and function, the type system supports three additional cv-qualified versions of that type (const, volatile, and const volatile).

The following chart visually depicts how these categories overlap:

<table>
    <thead>
        <tr>
					<th></th>
					<th> Primary Categories</th>
					<th colspan="3">Composite Categories</th>
				</tr>
		</thead>
		<tbody>
			<tr>
				<td rowspan="4">fundamental</td>
				<td>void</td>
				<td></td>
				<td></td>
				<td></td>
			</tr>
			<tr>
				<td>std::nullptr_t</td>
				<td></td>
				<td rowspan="7">scalar</td>
				<td rowspan="10">object</td>
			</tr>
			<tr>
				<td>integral</td>
				<td rowspan="2">arithmetic</td>
			</tr>
			<tr>
				<td>floating point</td>
			</tr>
			<tr>
			<td rowspan="10">compound</td>
				<td>pointer</td>
				<td></td>
			</tr>
			<tr>
				<td>member object pointer</td>
				<td rowspan="2">member pointer</td>
			</tr>
			<tr>
				<td>member function pointer</td>
			</tr>
			<tr>
				<td>enum</td>
				<td></td>
			</tr>
			<tr>
				<td>union</td>
				<td></td>
				<td></td>
			</tr>
			<tr>
				<td>class</td>
				<td></td>
				<td></td>
			</tr>
			<tr>
				<td>array</td>
				<td></td>
				<td></td>
			</tr>
			<tr>
				<td>l-value reference</td>
				<td rowspan="2">reference</td>
				<td></td>
				<td></td>
			</tr>
			<tr>
				<td>r-value reference</td>
				<td></td>
				<td></td>
			</tr>
			<tr>
				<td>function</td>
				<td></td>
				<td></td>
				<td></td>
			</tr>
		</tbody>
</table>
