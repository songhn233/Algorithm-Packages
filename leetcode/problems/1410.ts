const entityParser = (text: string) =>
  text
    .replace(/&quot;/g, '"')
    .replace(/&gt;/g, '>')
    .replace(/&apos;/g, "'")
    .replace(/&lt;/g, '<')
    .replace(/&frasl;/g, '/')
    .replace(/&amp;/g, '&')
