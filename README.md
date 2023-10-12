<p align="center">
 <img width="450" src="https://github.com/theiskaa/replace/assets/59066341/3959ea69-a62e-4aed-bb99-cbc92db7253e" alt="replace Logo">
</p>

---

The replace/rp is a versatile tool that enables you to perform efficient replacement operations within specified files. This tool facilitates the seamless update of content across multiple files simultaneously. Whether you need to correct a typo, update a key term, or make any other content changes.

## Usage

1. Identify the content you want to replace (represented by `{X}`).
2. Specify the replacement content (represented by `{Y}`).
3. Select the target files or folders (represented by `{Z}`) where the replacement operation will be applied.

## Example

Suppose you have a collection of Markdown files where the word "color" is used, but you want to standardize it as "colour." You can achieve this using the replace as follows:

```shell
rp "color" "colour" "folder_name/*.md"
```

In this example:
- `{X}` is "color"
- `{Y}` is "colour"
- `{Z}` is the set of Markdown files within the specified folder (`folder_name`)

Executing the above command will systematically replace all occurrences of "color" with "colour" within the designated Markdown files.

## Syntax
```
rp {OPTIONS} {X} {Y} ... {Z}
```

The syntax of the replace involves three main components: `{OPTIONS}`, `{X}`, `{Y}`, and one or more instances of `{Z}`. The components are explained below:

- `{OPTIONS}`: You can use the `-w` or `--word` option to enable word-based replacements, ensuring an exact, space-free match for segments to be replaced.
- `{X}` and `{Y}`: These are both strings representing the source and target for replacement, respectively. By specifying `{X}` as the content to be replaced and `{Y}` as the content to replace it with, you control what changes are made within the files.
- `{Z}` elements: These denote the files in which the replacement operation will take place. Each `{Z}` can refer to a folder or file name, allowing you to define the scope of files to be included in the replacement operation. If `{Z}` is not provided at all, the "replace" operation will be applied to all matching values found under the current folder. This means that any occurrence of `{X}` within the files located in the current directory will be replaced with `{Y}`.
